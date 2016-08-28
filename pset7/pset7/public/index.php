<?php

    // configuration
    require("../includes/config.php"); 
    
    // combine data from lookup and query into associative array '$positions'
    $positions = [];
    
    // error checking
    if (empty($_SESSION["id"]))
    {
        apologize("Please log in.");
    }
    
    // query database for symbol and shares for one specific user_id
    $rows = CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    
    /**
    // error checking
    if(count($rows) != 1)
    {
        apologize("Your portfolio is empty.");
        break;
    }
    */
    
    // store values in $positions array
    foreach($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if($stock != false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "symbol" => $row["symbol"],
                "shares" => $row["shares"],
                "value" => $row["shares"] * $stock["price"]
                ];
        }
    }
    
    // cash
    $cash = CS50::query("SELECT username, cash FROM users WHERE id = ?", $_SESSION["id"]);
    
    // error checking
    if(count($cash) != 1)
    {
        apologize("An error occured. Please try again later.");
        break;
    }

    
    // render portfolio
    render("portfolio.php", ["positions" => $positions, "cash" => $cash, "title" => "Portfolio"]);

?>
