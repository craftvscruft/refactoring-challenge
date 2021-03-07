let questions = [
  {
    question: "Which language is used for styling web pages?",
    option: ["CSS", "HTML", "JQuery", "XML"],
  },
  {
    question: "What is HTML?",
    option: [
      "Hyper text Markup Language",
      "Hyper tool Markup Language",
      "Hyper link Manipulation Language",
      "Hyper text Manipulation Language",
    ],
  },
  {
    question: "Which of the following sentence is true about Div tag?",
    option: [
      "A block-level element?",
      "Defines a paragraph",
      "Creates a line break",
      "Styles a web page",
    ],
  },
  {
    question:
      " Which of the following property sets the shadow for a box element?",
    option: ["box-shadow", "set-shadow", "canvas-shadow", "shadow"],
  },
  {
    question:
      "What is the correct HTML for adding a background color of yellow?",
    option: [
      '<body style= "background-color: #FFFF00">',
      '<body style= "background-color: #FFB6C1">',
      "all of the above",
      "none of the above",
    ],
  },
  {
    question: "How to set style of a certain HTML element with id of “quiz”?",
    option: ["#quiz{}", ".quiz{}", ".quiz()", "Id.quiz{}"],
  },
  {
    question: "How do you add comments in CSS?",
    option: ["/* comment*/", "<!—comment-->", "// comment", "//comment"],
  },
  {
    question:
      "Given a margin: 10px 20px 5px 15px \n Where does 5px value will assigned?",
    option: ["Bottom", "Right", "Left", "Top"],
  },
  {
    question:
      "Which of the following attributes is used to add link to any element?",
    option: ["href", "Link", "ref", "li"],
  },
  {
    question: "Why is this keyword not preferred in JavaScript?",
    option: [
      "Functions should not access the global object",
      "Highly memory consuming",
      "Very inefficient to use",
      "Functions should access the global objects",
    ],
  },
  {
    question:
      "Which method removes the last element from an array and returns that element?",
    option: ["pop()", "pop()", "pop()", "push()"],
  },
  {
    question: "The object has three object attributes namely ________",
    option: [
      "Prototype, class, object’s extensible flag",
      " Prototype, class, objects’ parameters",
      " Native object, Classes and Interfaces and Object’s extensible flag",
      "lClass, parameters, object’s extensible flag",
    ],
  },
  {
    question: "JavaScript is interpreted by _________",
    option: ["Client", "Server", "Object", "None of the above"],
  },
  {
    question: 'What is mean by "this" keyword in javascript?',
    option: [
      "It refers current object",
      "It refers previous object",
      "It is variable which contains value",
      "None of the above",
    ],
  },
  {
    question: "A function with no return value is called______",
    option: ["Procedures", "Method", "Static function", "Dynamic function"],
  },
];

const questionContainer = document.querySelector("#question");

const allRadioButtons = Array.from(
  document.querySelectorAll("input[name=option]")
);

const nextButton = document.querySelector(".next");

let resultContainer = document.getElementById("result");

let currentQuestionIndex = 0;
let score = 0;
let body = document.querySelector("body");
//select message
let messageContainer = document.getElementById("message");
//write a function to display questions
function getQuestion() {
  // define a variable that selects random options
  const answers = questions[currentQuestionIndex].option;
  // for each input display questions
  questionContainer.textContent =
    currentQuestionIndex + 1 + ". " + questions[currentQuestionIndex].question;
  console.log(questionContainer.textContent);
  allRadioButtons.forEach(function (input, i) {
    // Set radio button check value
    input.value = answers[i];
    //reset value
    input.checked = false;
    // Display the options text
    let ansContainer = input.nextElementSibling;
    ansContainer.textContent = answers[i];
  });
}
getQuestion();

//add EventListener to next button
nextButton.addEventListener("click", handleNextQuestion);
function handleNextQuestion() {
  // provide condition to correct answer
  let selectAnswer = document.querySelector("input[type=radio]:checked");
  if (!selectAnswer) {
    console.log("No answer. TODO: show message.");
    return;
  }
  let ans = selectAnswer.value;
  // update number of correctly answered questions:
  // result.innerHTML = 'Score: ' + score;
  if (ans == questions[currentQuestionIndex].option[0]) {
    score += 5;
    // alert('correct answer');
    messageContainer.innerText = "Great Job! Your Answer is correct";
  } else {
    // alert('answer is wrong');
    messageContainer.innerText = "Oops! Your answer is wrong";
  }
  // next question
  currentQuestionIndex++;
  if (currentQuestionIndex >= questions.length) {
    //display score
    body.innerHTML = "Well Done! Your Score:" + score;
    // restart
    currentQuestionIndex = 0;
  }
  resultContainer.innerHTML = "Score: " + score;
  getQuestion();
}
