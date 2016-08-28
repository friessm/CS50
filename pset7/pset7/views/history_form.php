<div>

    <table class="table table-striped">
    
        <thead>
            <tr>
                <th>Action</th>
                <th>Symbol</th>
                <th>Shares</th>
                <th>Price at transaction</th>
                <th>Timestamp</th>
            </tr>
        </thead>
    
        <tbody>
            
            <?php foreach($symbols as $symbol): ?>
            
            <tr>
                <td><?= $symbol["type"] ?></td>
                <td><?= $symbol["symbol"] ?></td>
                <td><?= $symbol["shares"] ?></td>
                <td><?= "$" . $symbol["price_trans"] ?></td>
                <td><?= $symbol["date"] ?></td>
                
            </tr>
            
            <?php endforeach ?>

        </tbody>
    
    </table>
    
</div>