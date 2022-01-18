/**
 * @author  Sowa Takayanagi
 * @since   1/18/2022 2:57 PM
 * @version 1.0.0
 */
import {ChangeEvent, FC, FormEvent, useState} from "react";
import axios from "axios";
import {Button, TextField} from "@mui/material";

type PostData = {
    text: string
}

export const Home: FC = () => {

    const [text, setText] = useState('');
    const handleSubmit = (ev: FormEvent<HTMLFormElement>) => {
        ev.preventDefault();
        axios.post("http://localhost:8081", {text: text})
            .then(r => console.log(r))
            .catch(err => console.log(err));
    };

    const handleChangeText = (ev: ChangeEvent<HTMLInputElement>) => {
        setText(ev.target.value);
    }


    return (
        <>
            <form onSubmit={handleSubmit}>
                <TextField
                    label='text'
                    value={text}
                    onChange={handleChangeText}
                />
                <Button
                    sx={{height: "50px", width: "170px"}}
                    type='submit'
                    variant='contained'
                    color='primary'
                >
                    Submit
                </Button>
            </form>
        </>
    )
}