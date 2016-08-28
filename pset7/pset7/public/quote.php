<?php

    require("../includes/config.php");
    
    // check if form is submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        // check if submitted form is empty
        if(empty($_POST["symbol"]))
        {
            apologize("Please provide a stock symbol.");
        }
        
        // get stock information from Yahoo
        $stock = lookup($_POST["symbol"]);
        
        // error checking
        if ($stock == false)
        {
            apologize("Invalid stock symbol");
        }
        
        // display output
        render("quote_result.php", ["stock" => $stock]);
        
    }
    
    else
    {
        render("quote_form.php", ["title" => "Quote"]);
    }
    
?>
