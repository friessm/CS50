<?php
    
    // display the stock information
    printf("Symbo: " . $stock["symbol"] . "<br>");
    printf("Name:" . $stock["name"] . "<br>");
    printf("Price: $" . number_format($stock["price"], 2));
    
?>