var express = require('express');
var app = express();
var fs = require("fs");
app.use(express.static('public'));

app.get('/tank/1/forward', function (req, res) {
        var exec = require('child_process').exec;
        var cmd = 'sudo /home/pi/RF24pi/RF24-master/examples_RPi/senddata 1 1';
        
        exec(cmd, function(error, stdout, stderr) {
             if(error) {
                console.log("Error: " + error.stack);
             }
             console.log('STDOUT: ' + stdout);
        });
        res.end();
})
app.get('/tank/1/backward', function (req, res) {
        var exec = require('child_process').exec;
        var cmd = 'sudo /home/pi/RF24pi/RF24-master/examples_RPi/senddata 1 2';
        
        exec(cmd, function(error, stdout, stderr) {
             if(error) {
                console.log("Error: " + error.stack);
             }
             console.log('STDOUT: ' + stdout);
             });
        res.end();
})
app.get('/tank/1/left', function (req, res) {
        var exec = require('child_process').exec;
        var cmd = 'sudo /home/pi/RF24pi/RF24-master/examples_RPi/senddata 1 3';
        
        exec(cmd, function(error, stdout, stderr) {
             if(error) {
                console.log("Error: " + error.stack);
             }
             console.log('STDOUT: ' + stdout);
             });
        res.end();
})
app.get('/tank/1/right', function (req, res) {
        var exec = require('child_process').exec;
        var cmd = 'sudo /home/pi/RF24pi/RF24-master/examples_RPi/senddata 1 4';
        
        exec(cmd, function(error, stdout, stderr) {
             if(error) {
                console.log("Error: " + error.stack);
             }
             console.log('STDOUT: ' + stdout);
             });
        res.end();
})
app.get('/tank/1/stop', function (req, res) {
        var exec = require('child_process').exec;
        var cmd = 'sudo /home/pi/RF24pi/RF24-master/examples_RPi/senddata 1 5';
        
        exec(cmd, function(error, stdout, stderr) {
             if(error) {
                console.log("Error: " + error.stack);
             }
             console.log('STDOUT: ' + stdout);
             });
        res.end();
})
app.get('/tank/1/fire', function (req, res) {
        var exec = require('child_process').exec;
        var cmd = 'sudo /home/pi/RF24pi/RF24-master/examples_RPi/senddata 1 6';
        
        exec(cmd, function(error, stdout, stderr) {
             if(error) {
                console.log("Error: " + error.stack);
             }
             console.log('STDOUT: ' + stdout);
             });
        res.end();
})

app.get('/tank/2/forward', function (req, res) {
        var exec = require('child_process').exec;
        var cmd = 'sudo /home/pi/RF24pi/RF24-master/examples_RPi/senddata 2 1';
        
        exec(cmd, function(error, stdout, stderr) {
             if(error) {
                console.log("Error: " + error.stack);
             }
             console.log('STDOUT: ' + stdout);
             });
        res.end();
})
app.get('/tank/2/backward', function (req, res) {
        var exec = require('child_process').exec;
        var cmd = 'sudo /home/pi/RF24pi/RF24-master/examples_RPi/senddata 2 2';
        
        exec(cmd, function(error, stdout, stderr) {
             if(error) {
                console.log("Error: " + error.stack);
             }
             console.log('STDOUT: ' + stdout);
             });
        res.end();
})
app.get('/tank/2/left', function (req, res) {
        var exec = require('child_process').exec;
        var cmd = 'sudo /home/pi/RF24pi/RF24-master/examples_RPi/senddata 2 3';
        
        exec(cmd, function(error, stdout, stderr) {
             if(error) {
                console.log("Error: " + error.stack);
             }
             console.log('STDOUT: ' + stdout);
             });
        res.end();
})
app.get('/tank/2/right', function (req, res) {
        var exec = require('child_process').exec;
        var cmd = 'sudo /home/pi/RF24pi/RF24-master/examples_RPi/senddata 2 4';
        
        exec(cmd, function(error, stdout, stderr) {
             if(error) {
                console.log("Error: " + error.stack);
             }
             console.log('STDOUT: ' + stdout);
             });
        res.end();
})
app.get('/tank/2/stop', function (req, res) {
        var exec = require('child_process').exec;
        var cmd = 'sudo /home/pi/RF24pi/RF24-master/examples_RPi/senddata 2 5';
        
        exec(cmd, function(error, stdout, stderr) {
             if(error) {
                console.log("Error: " + error.stack);
             }
             console.log('STDOUT: ' + stdout);
             });
        res.end();
})
app.get('/tank/2/fire', function (req, res) {
        var exec = require('child_process').exec;
        var cmd = 'sudo /home/pi/RF24pi/RF24-master/examples_RPi/senddata 2 6';
        
        exec(cmd, function(error, stdout, stderr) {
             if(error) {
                console.log("Error: " + error.stack);
             }
             console.log('STDOUT: ' + stdout);
             });
        res.end();
})

var server = app.listen(8081, function () {
               
    var host = server.address().address
    var port = server.address().port
                        
    console.log("Localhost instance app listening at http://%s:%s", host, port)
                        
})

var server2 = app.listen(8082, '192.168.200.33', function () {
                         
    var host = server2.address().address
    var port = server2.address().port
                         
    console.log("External instance app listening at http://%s:%s", host, port)
                         
})