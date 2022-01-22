package main

import (
	"database/sql"
	"encoding/json"
	"fmt"
	"log"
	"net/http"

	_ "github.com/lib/pq"
	"golang.org/x/crypto/bcrypt"
)

type AuthData struct {
	Username string `json:"username,omitempty"`
	Password string `json:"password"`
}

func main() {
	http.HandleFunc("/signup", Register)
	http.HandleFunc("/signin", LogIn)

	initDB()

	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}

var db *sql.DB

func initDB() {
	var err error
	conn := "host=localhost port=5432 user=root dbname=gots sslmode=disable"
	db, err = sql.Open("postgres", conn)
	if err != nil {
		panic(err)
	}
}

func Register(w http.ResponseWriter, r *http.Request) {
	req := &AuthData{}
	if err := json.NewDecoder(r.Body).Decode(req); err != nil {
		//fmt.Errorf("could not decode request: %w", err)
		w.WriteHeader(http.StatusBadRequest)
		return
		fmt.Printf("%w", err)
		fmt.Println("could not decode request")
	} else {
		fmt.Println("success")
	}

	hashedPassword, err := bcrypt.GenerateFromPassword([]byte(req.Password), 8)
	if err != nil {
		fmt.Printf("%w", err)
		fmt.Println("could not generate hash from password")
	} else {
		fmt.Println("success")
	}

	if _, err = db.Query("insert into users values ($1, $2)", req.Username, string(hashedPassword)); err != nil {
		fmt.Println("could not insert hashed password")
		fmt.Printf("%w", err)
		return
	} else {
		fmt.Println("success")
	}

	//defer rows.Close()

}

func LogIn(w http.ResponseWriter, r *http.Request) {
	req := &AuthData{}
	var err error
	if err := json.NewDecoder(r.Body).Decode(&req); err != nil {
		w.WriteHeader(http.StatusBadRequest)
		return
	}
	defer r.Body.Close()

	row := db.QueryRow("select password from users where usrename=$1", req.Username)

	storedData := &AuthData{}

	if err = row.Scan(storedData.Password); err != nil {
		if err == sql.ErrNoRows {
			fmt.Errorf("%w", err)
			fmt.Println("could not scan password")
			w.WriteHeader(http.StatusInternalServerError)
		} else {
			fmt.Println("scan success")
		}

	}
	if err = bcrypt.CompareHashAndPassword([]byte(storedData.Password), []byte(req.Password)); err != nil {
		w.WriteHeader(http.StatusUnauthorized)
		fmt.Println("could not authenticate")
		fmt.Printf("%w", err)
	} else {
		fmt.Println("AUTH SUCCESSSSSSSSSSSSSSSSSSSSS")
	}
}
