const express = require("express");

var app = express();

app.listen(8080, function () {
  console.log("server on 8080 port!");
});

app.get("/", (req, res) => {
  res.send("<h1>express server on port 8080</h1>");
});
