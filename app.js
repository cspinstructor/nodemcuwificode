const express = require('express');
const server = express();

server.get('/', (req, res) => {
  res.status(200).send("Hello from node.js");
});

server.listen(3000, () => {
  console.log(`server started on port 3000`);
});
