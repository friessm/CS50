<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        
        // empty returns true if checked variable is empty
        // check for username
        if (empty($_POST["username"]))
        {
            apologize("You must provide a username.");
        }
        
        // check for password
        if (empty($_POST["password"]))
        {
            apologize("You must provide a password.");
        }
        
        // check for password confirmation
        if (empty($_POST["confirmation"]))
        {
            apologize("You must confirm your password.");
        }
        
        // ensure password equals password confirmation
        if ($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Your password and your password confirmation are not equal.");
        }
        
        // insert new user into the database
        $user = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
        
        // if username is not already in the database
        // query returns 0, if INSERT fails (for example, if username already exists)
        if ($user == 1)
        {
            // get user id
            $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];

            // remember that user is logged in after registration
            $_SESSION["id"] = $id;

            // redirect to index.php 
            redirect("index.php"); 
        }
        
        else
        {
            apologize("This user already exists.");
        }
        
    }

?>