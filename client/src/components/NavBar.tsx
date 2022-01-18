/**
 * @author  Sowa Takayanagi
 * @since   1/18/2022 2:59 PM
 * @version 1.0.0
 */
import {ElementType, FC} from "react";
import {AppBar, Box, styled, Toolbar} from "@mui/material";


export const Navbar: ElementType = styled(AppBar)`
    height: 80;
    display: flex;
    position: static;
    fontWeight: bold;
    padding: 5px 20px
`;

export const NavBar: FC = () => {

    return (
        <Box sx={{borderBottom: "1px solid #869096"}}>
            <Navbar color='transparent' variant='dense'>
                <Toolbar disableGutters={true}>

                </Toolbar>
            </Navbar>
        </Box>
    )

}