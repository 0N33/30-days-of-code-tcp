const boardElement = document.getElementById('board');
const statusElement = document.getElementById('status');
const resetBtn = document.getElementById('resetBtn');
let cells = document.querySelectorAll('.cell');

let currentPlayer = 'X';
let gameState = ["", "", "", "", "", "", "", "", ""];
let gameActive = true;

// SVG Graphics
const xIcon = `<svg viewBox="0 0 24 24" stroke="currentColor" stroke-width="2" fill="none"><path d="M18 6L6 18M6 6l12 12"></path></svg>`;
const oIcon = `<svg viewBox="0 0 24 24" stroke="currentColor" stroke-width="2" fill="none"><circle cx="12" cy="12" r="9"></circle></svg>`;

const winningConditions = [
    [0, 1, 2], [3, 4, 5], [6, 7, 8], // Rows
    [0, 3, 6], [1, 4, 7], [2, 5, 8], // Columns
    [0, 4, 8], [2, 4, 6]             // Diagonals
];

function handleCellClick(e) {
    const clickedCell = e.target;
    const cellIndex = parseInt(clickedCell.getAttribute('data-index'));

    if (gameState[cellIndex] !== "" || !gameActive) return;

    gameState[cellIndex] = currentPlayer;
    clickedCell.innerHTML = currentPlayer === 'X' ? xIcon : oIcon;
    clickedCell.style.color = currentPlayer === 'X' ? '#00d2ff' : '#ff007f';

    checkResult();
}

function checkResult() {
    let roundWon = false;
    for (let condition of winningConditions) {
        let [a, b, c] = condition;
        if (gameState[a] && gameState[a] === gameState[b] && gameState[a] === gameState[c]) {
            roundWon = true;
            // Highlight winning cells
            [a, b, c].forEach(index => cells[index].classList.add('winner'));
            break;
        }
    }

    if (roundWon) {
        statusElement.innerText = `Player ${currentPlayer} Wins!`;
        gameActive = false;
        return;
    }

    if (!gameState.includes("")) {
        statusElement.innerText = "It's a Draw!";
        gameActive = false;
        return;
    }

    currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
    statusElement.innerText = `Player ${currentPlayer}'s Turn`;
}

function restartGame() {
    currentPlayer = 'X';
    gameState = ["", "", "", "", "", "", "", "", ""];
    gameActive = true;
    statusElement.innerText = "Player X's Turn";
    cells.forEach(cell => {
        cell.innerHTML = "";
        cell.classList.remove('winner');
    });
}

cells.forEach(cell => cell.addEventListener('click', handleCellClick));
resetBtn.addEventListener('click', restartGame);