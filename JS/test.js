var url = "https://jsonplaceholder.typicode.com/posts/1";

fetch(url, {
  method: "POST",
  headers: {
    "Content-type": "application/json",
  },
  body: JSON.stringify({
    title: "Test",
    body: "I am testing!",
    userId: 1,
  }),
})
  .then((res) => res.json())
  .then((data) => console.log(data));
