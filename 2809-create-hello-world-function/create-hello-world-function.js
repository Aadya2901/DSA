function createHelloWorld() {
  return function (..._) {
    return 'Hello World';
  };
}

const hello = createHelloWorld();
console.log(hello()); // Output: "Hello World"
