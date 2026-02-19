var http = require('http');
http.createServer(function (req, res) {
  res.write('HTTP Server in Node.js\n');
  res.end('Hello World!');
}).listen(8080);
console.log('Server running at http://localhost:8080/');