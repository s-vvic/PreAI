const express = require("express");

const app = express();

var port = 8080;

app.listen(port, () => {
  console.log("server strated");
});

app.get("/", (req, res) => {
  res.send("Hello World");
  console.log(res.body);
});
