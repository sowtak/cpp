import axios from "axios";

type TestData = {
    payload: string
}

const data: TestData = {
    payload: "Test"
}

axios.post("http://localhost:8081", {data})
    .then(r => console.log(r))
    .catch((err) => console.log(err));
