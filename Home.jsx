import React from "react";
import { Button } from "@material-ui/core";
import { useAuth0 } from "@auth0/auth0-react";
import {
  makeStyles,
  AppBar,
  Toolbar,
  Typography,
  Box,
  Grid,
} from "@material-ui/core";
import { withRouter } from "react-router-dom";

//Material-UI Formatting
const useStyles = makeStyles((theme) => ({
  root: {
    flexGrow: 1,
    position: "relative",
  },
  hero: {
    backgroundImage: `Linear-gradient(rgba(0, 0, 0, 0.5), rgba(0, 0, 0, 0.5)), url('https://images.unsplash.com/photo-1450101499163-c8848c66ca85?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=500&q=60')`,
    height: 557,
    backgroundPosition: "center",
    backgroundRepeat: "no-repeat",
    backgroundSize: "cover",
    position: "relative",
    display: "flex",
    justifyContent: "center",
    flexDirection: "column",
    alignItems: "center",
    color: "#fff",
    textAlign: "center",
  },
  tagline: {
    fontSize: "4rem",
    padding: 2,
    [theme.breakpoints.down("sm")]: {
      fontSize: "3em",
    },
  },
  vp: {
    fontSize: "2rem",
    padding: 30,
    [theme.breakpoints.down("sm")]: {
      fontSize: "1.5em",
    },
  },
  getStartedButton: {
    marginLeft: 30,
    marginRight: 30,
    marginTop: 10,
    padding: 10,
    fontSize: "1rem",
    fontWeight: "bold",
    width: 180,
    backgroundColor: "#E63946",
    color: "white",
    "&:hover": {
      backgroundColor: "#ED747E",
    },
  },
  toolbar: {
    minHeight: 0,
    paddingTop: theme.spacing(2),
    paddingBottom: theme.spacing(2),
  },
  headText: {
    textAlign: "left",
    marginLeft: 10,
    flex: 1,
    fontSize: 20,
    [theme.breakpoints.down("xs")]: {
      fontSize: 15,
    },
  },
  appBar: {
    backgroundColor: "primary",
  },
  LogInbutton: {
    marginRight: 10,
    fontWeight: "bold",
    [theme.breakpoints.down("xs")]: {
      fontSize: "0.6rem",
    },
  },
}));

//Main Function
const Home = (props) => {
  //const { history } = props;
  const classes = useStyles();
  const { loginWithRedirect, isAuthenticated } = useAuth0();
  return (
    <div className={classes.root}>
      {/* Displays Appbar for Homepage*/}
      <AppBar position="static" className={classes.appBar}>
        <Toolbar className={classes.toolbar}>
          <Grid item xs={0} md={1} />
          <Typography component="div" className={classes.headText}>
            Budget Allocator
          </Typography>
          <Button
            variant="outlined"
            color="secondary"
            className={classes.LogInbutton}
            onClick={() => {
              console.log("Open LogIn Page");
            }}
          >
            Log In
          </Button>
          <Grid item xs={0} md={1} />
        </Toolbar>
      </AppBar>

      {/* Displays Hero Image and Content */}
      <Box className={classes.hero}>
        <Box className={classes.tagline}>Manage Your Expenses</Box>
        <Box className={classes.vp}>Your Solution for Smart Budgeting</Box>
        <br></br>
        <Button
          variant="contained"
          className={classes.getStartedButton}
          onClick={() => loginWithRedirect()} 
        >
          Get Started
        </Button>
      </Box>
    </div>
  );
};

export default withRouter(Home);
