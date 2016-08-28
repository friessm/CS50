<?php

    require("../includes/config.php");
    
    if(empty($_SESSION["id"]))
    {
        apologize("You are not logged in. Please log in.");
    }
    
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // error checking
        if(empty($_POST["symbol"]))
        {
            apologize("Please provide a stock symbol.");
        }
        
        // check current price of the stock symbol
        $stock = lookup($_POST["symbol"]);
        
        // error checking
        if ($stock == false)
        {
            apologize("Invalid stock symbol");
        }
        
        // get the number of shares for the provided stock symbol
        $shares = CS50::query("SELECT shares FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        // calculate total sell price
        $sell_price = $shares[0]["shares"] * $stock["price"];
        
        // update portfolio
        CS50::query("UPDATE portfolios SET shares = 0 WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        // update cash
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $sell_price, $_SESSION["id"]);
        
        // update history table
        $history = CS50::query("INSERT INTO history (user_id, type, symbol, shares, price_trans) VALUES (?, ?, ?, ?, ?)",
                                $_SESSION["id"], "sold", $_POST["symbol"], $shares[0]["shares"], $stock["price"]);
        
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
        // select all stocks in the users portfolio
        $rows = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        
        // initialise array to store stock symbols
        $stocks = [];
        
        // put all stocks in the array
        foreach($rows as $row)
        {
            $stock = $row["symbol"];
            $stocks[] = $stock;
        }
        
        // render the sell form so users can choose which share to sell
        render("sell_form.php", ["title" => "Sell", "stocks" => $stocks]);
    }
    
?>
