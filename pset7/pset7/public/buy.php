<?php

    require("../includes/config.php");
    
    if(empty($_SESSION["id"]))
    {
        apologize("You are not logged in. Please log in.");
    }
    
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check whether there is input or not
        if(empty($_POST["symbol"]))
        {
            apologize("Please enter a stock symbel.");
        }
        if(empty($_POST["shares"]))
        {
            apologize("Please enter the number of shares you like to buy.");
        }
        
        // check whether input is valid
        if(preg_match("/^\d+$/", $_POST["shares"]) == false)
        {
            apologize("Please enter a non-negative integer as number of shares.");
        }
        
        // get stock information from Yahoo, including stock price
        $stock = lookup($_POST["symbol"]);
        
        // error checking
        if($stock == false)
        {
            apologize("Invalid stock symbol.");
        }
        
        // get current cash balance from user
        $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        
        // check whether cash balance is enough to buy the chosen number of shares
        $cost = $stock["price"] * $_POST["shares"];
        if($cost > $cash[0]["cash"])
        {
            apologize("You do not have enough cash to buy this amount of stocks.");
        }
        
        // enter only upper case letters to your database (symbol)
        $_POST["symbol"] = strtoupper($_POST["symbol"]);
        
        // insert into portofolios table: shares, symbol
        $insert = CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES (?, ?, ?) 
                    ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", 
                    $_SESSION["id"], $_POST["symbol"], $_POST["shares"]);
        
        // error checking
        if ($insert == 0)
        {
            apologize("Could not buy stocks.");
        }
        
        // insert into users table: cash
        $update = CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $cost, $_SESSION["id"]);
        
        // error checking
        if ($update == 0)
        {
            apologize("Could not buy stocks.");
        }
        
        // update history table
        $history = CS50::query("INSERT INTO history (user_id, type, symbol, shares, price_trans) VALUES (?, ?, ?, ?, ?)",
                                $_SESSION["id"], "bought", $_POST["symbol"], $_POST["shares"], $stock["price"]);
        
        // error check history SQL
        if ($history == 0)
        {
            apologize("Couldn't update history.");
        }
        
        // redirect to portfolio
        redirect("/");
    }
    
    // if nothing has been submitted via POST, show the input page
    else
    {

        // render the sell form so users can choose which share to sell
        render("buy_form.php");
    }
    
?>
