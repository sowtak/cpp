package main

import (
	"encoding/json"
	"fmt"
	"github.com/gorilla/mux"
	"net/http"
)

func main() {
	run()
}

func run() {
	r := mux.NewRouter()
	r.HandleFunc("/", h)

	http.ListenAndServe(":8081", r)
}

type TestData struct {
	payload string
}

func h(w http.ResponseWriter, r *http.Request) {
	defer r.Body.Close()
	var in TestData
	if err := json.NewDecoder(r.Body).Decode(&in); err != nil {
		fmt.Println(err)
	}
	http.Redirect(w, r, "/success", 302)
}
