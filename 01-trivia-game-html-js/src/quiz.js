const questionContainer = document.querySelector("#question");

const allRadioButtons = Array.from(
  document.querySelectorAll("input[name=option]")
);

const nextButton = document.querySelector(".next");

const resultContainer = document.getElementById("result");

let currentQuestionIndex;
let score;
const body = document.querySelector("body");

const messageContainer = document.getElementById("message");

function displayQuestionOptionText(radioButton, text) {
  const ansContainer = radioButton.nextElementSibling;
  ansContainer.textContent = text;
}

function displayQuestion() {
  const answers = questions[currentQuestionIndex].option;

  questionContainer.textContent =
    currentQuestionIndex + 1 + ". " + questions[currentQuestionIndex].question;
  allRadioButtons.forEach(function (radioButton, i) {
    radioButton.value = answers[i];
    radioButton.checked = false;
    displayQuestionOptionText(radioButton, answers[i]);
  });
}

nextButton.addEventListener("click", handleNextQuestion);

function updateScore(selectedAnswer, correctAnswer) {
  if (selectedAnswer == correctAnswer) {
    score += 5;
    messageContainer.innerText = "Great Job! Your Answer is correct";
  } else {
    messageContainer.innerText = "Oops! Your answer is wrong";
  }
}

function displayScore(score) {
  resultContainer.innerHTML = "Score: " + score;
}

function displayFinalScore(score) {
  body.innerHTML = "Well Done! Your Score:" + score;
}

function restart() {
  currentQuestionIndex = 0;
  score = 0;
}

function advanceToNextQuestion() {
  currentQuestionIndex++;
  if (currentQuestionIndex >= questions.length) {
    displayFinalScore(score);
    restart();
  }
}

function handleNextQuestion() {
  const checkedRadioButton = document.querySelector(
    "input[type=radio]:checked"
  );
  if (!checkedRadioButton) {
    console.log("No answer. TODO: show message.");
    return;
  }
  const selectedAnswer = checkedRadioButton.value;
  const correctAnswer = questions[currentQuestionIndex].option[0];
  updateScore(selectedAnswer, correctAnswer);
  advanceToNextQuestion();
  displayScore(score);
  displayQuestion();
}

restart();
displayQuestion();
