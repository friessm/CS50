#!/usr/bin/env php
<?php

    /**
     * import.php
     * 
     * Computer Science 50 
     * Problem set 8
     * 
     * Marco Friess
     * 
     * Import data into MySQL table
     * Data obtained from http://download.geonames.org/export/dump/
     */

    // include config
    require(__DIR__ . "/../includes/config.php");
    
    // check user input
    if($argc != 2)
    {
        echo "Usage: ./import /path/to/text.txt \r\n";
        excit(1);
    }

    // check if file exists
    if(!file_exists($argv[1]))
    {
        echo "File does not exist. Please check your path \r\n";
        exit(1);
    }
    
    // check if file is readable
    if(!is_readable($argv[1]))
    {
        echo "File is not readable. Please check the file extension. \r\n";
        exit(1);
    }
    
    // if file exists and it is readable
    echo "File " . $argv[1] . " found. \r\n";
    
    // open the file and error checking
    $handle = fopen($argv[1], "r");
    if($handle == false)
    {
        echo "File could not be opened. \r\n";
        break;
    }
    
    // read from txt file line by line and store in database
    while(($data = fgetcsv($handle, 1000, "\t")) !== false)
    {
        // insert into database
        $insert = CS50::query("INSERT INTO places (`country_code`, `postal_code`, `place_name`, `admin_name1`, 
                    `admin_code1`, `admin_name2`, `admin_code2`, `admin_name3`, `admin_code3`, 
                    `latitude`, `longitude`, `accuracy`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)",
                    $data[0], $data[1], $data[2], $data[3], $data[4], $data[5],$data[6], $data[7], $data[8],
                    $data[9], $data[10], $data[11]);
    }
    
    // close file
    fclose($handle);
    
    // print success message
    print("Data import successful.\r\n");

?>