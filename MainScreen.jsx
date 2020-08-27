import React, { useState } from "react";
import {
  Typography,
  makeStyles,
  Box,
  TextField,
  InputAdornment,
  Button,
} from "@material-ui/core";
import { useAuth0 } from "@auth0/auth0-react";

//Material-UI Formatting
const useStyles = makeStyles((theme) => ({
  drawerHeader: {
    display: "flex",
    alignItems: "center",
    padding: theme.spacing(0, 1),
    // necessary for content to be below app bar
    ...theme.mixins.toolbar,
    justifyContent: "flex-end",
  },
  content: {
    flexGrow: 1,
    paddingLeft: theme.spacing(25),
    paddingTop: theme.spacing(2),
    paddingRight: theme.spacing(15),
    [theme.breakpoints.down("md")]: {
      paddingLeft: theme.spacing(20),
      paddingRight: theme.spacing(8),
      alignItems: "center",
    },
    [theme.breakpoints.down("sm")]: {
      padding: theme.spacing(3),
      paddingTop: theme.spacing(2),
      paddingLeft: theme.spacing(5),
    },
  },
  dateButton: {
    backgroundColor: "#edad74",
  },
  date: {
    color: "#000000",
    fontWeight: "bold",
  },
  mainBox: {
    marginTop: theme.spacing(8),
    [theme.breakpoints.down("md")]: {
      marginTop: theme.spacing(5),
    },
  },
  mainContent: {
    fontWeight: "bold",
    marginBottom: theme.spacing(8),
    [theme.breakpoints.down("md")]: {
      fontSize: "0.90rem",
    },
    [theme.breakpoints.down("sm")]: {
      fontSize: "0.80rem",
    },
  },
  contentBox: {
    marginLeft: theme.spacing(5),
    marginTop: -15,
    width: "25ch",
    [theme.breakpoints.down("md")]: {
      marginTop: theme.spacing(3),
      width: "35ch",
    },
    [theme.breakpoints.down("sm")]: {
      marginTop: -15,
      width: "25ch",
    },
    [theme.breakpoints.down("xs")]: {
      marginTop: theme.spacing(3),
      width: "35ch",
    },
  },
  saveButton: {
    marginLeft: "30%",
    width: 120,
    height: 40,
    marginTop: -15,
    marginBottom: 50,
    fontWeight: "bold",
    backgroundColor: "#5e3003",
    color: "white",
    "&:hover": {
      backgroundColor: "#91683f",
    },
  },
}));

//Main Function
const MainScreen = () => {
  const classes = useStyles();
  const { user, isAuthenticated, logout } = useAuth0();
  //Date Formatting Options
  const DATE_OPTIONS = {
    weekday: "short",
    year: "numeric",
    month: "short",
    day: "numeric",
  };

  //Storing User Input Value temporarily
  const [monthlyBudget, setSalary] = useState("");
  const [expectedMonthlyExpense, setExpense] = useState("");
  const [expectedMonthlySaving, setSaving] = useState(
    monthlyBudget - expectedMonthlyExpense
  );

  const fetchData = () => {
    console.log(user.sub);
    fetch("http://localhost:3001/users", {
      method: "post",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        id: user.sub,
        month: "Aug",
        monthlyBudget: monthlyBudget,
        expectedMonthlyExpenses: expectedMonthlyExpense,
      }),
    });
  };

  //Calculates saving
  function calculateSaving() {
    setSaving(monthlyBudget - expectedMonthlyExpense);
  }

  function clickEvents() {
    isAuthenticated && fetchData();
    
    calculateSaving();
  }

  return (
    <main className={classes.content}>
      <div className={classes.drawerHeader} />

      {/* Keeps main content away from Menu Drawer */}
      <Box className={classes.content}>
        <Button variant="outlined" disabled className={classes.dateButton}>
          <Typography className={classes.date}>
            {new Date().toLocaleDateString("en-US", DATE_OPTIONS)}
          </Typography>
        </Button>

        {/* Displays the TextFields */}
        <Box className={classes.mainBox}>
          <Typography className={classes.mainContent}>
            YOUR MONTHLY SALARY :
            <TextField
              label="Total Salary"
              id="outlined-start-adornment"
              InputProps={{
                startAdornment: (
                  <InputAdornment position="start">Rs. </InputAdornment>
                ),
              }}
              variant="outlined"
              type="number"
              value={monthlyBudget}
              onChange={(e) => setSalary(+e.target.value)}
              className={classes.contentBox}
            />
          </Typography>

          <Typography className={classes.mainContent}>
            EXPECTED MONTHLY EXPENSE :
            <TextField
              id="outlined-start-adornment"
              InputProps={{
                startAdornment: (
                  <InputAdornment position="start">Rs. </InputAdornment>
                ),
              }}
              label="Expected Expense"
              variant="outlined"
              type="number"
              value={expectedMonthlyExpense}
              onChange={(e) => {
                setExpense(+e.target.value);
              }}
              className={classes.contentBox}
            />
          </Typography>

          <Button
            variant="contained"
            onClick={clickEvents}
            className={classes.saveButton}
          >
            Save
          </Button>

          {/* Displays the calculated saving */}
          <Typography className={classes.mainContent}>
            EXPECTED SAVINGS : Rs. {expectedMonthlySaving}
          </Typography>

          {isAuthenticated && (
            <Button
              variant="contained"
              onClick={() => logout()}
              className={classes.saveButton}
            >
              Log Out
            </Button>
          )}
        </Box>
      </Box>
    </main>
  );
};

export default MainScreen;