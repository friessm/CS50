<?php

    require("../includes/config.php");
    
    if(empty($_SESSION["id"]))
    {
        apologize("You are not logged in. Please log in.");
    }
    
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // error checking
        if(empty($_POST["deposit"]))
        {
            apologize("Please enter the amount of cash you would like to deposit.");
        }
        
        // check whether input is valid

        $deposit = CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST["deposit"], $_SESSION["id"]);
        
        // redirect to portfolio
        redirect("/");
    }
    
    // if nothing has been submitted via POST, show the input page
    else
    {

        // render the sell form so users can choose which share to sell
        render("deposit_form.php");
    }

    
?>
