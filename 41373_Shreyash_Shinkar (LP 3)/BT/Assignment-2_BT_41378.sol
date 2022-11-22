//SPDX-License-Identifier: MIT 
import "hardhat/console.sol";
pragma solidity ^0.4.25;

contract Bank{
    int bal;

    constructor() public
    {
        bal = 0;

    }

    function getBalance() view public returns(int){
        return bal;
    }
    function withdraw(int amt) public{
        if(bal - amt < 0){
            console.log("Not enough balance");
        }
        else{
            bal = bal - amt;
            console.log("Money withdrawn");
        }
        
    }
    function deposit(int amt) public{
        bal = bal + amt;
        console.log("Money deposited");
    }
}