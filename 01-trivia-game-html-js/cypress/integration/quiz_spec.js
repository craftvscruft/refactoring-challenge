describe('Quiz', () => {
    const url = 'http://127.0.0.1:5500/01-trivia-game-html-js/src/index.html';
    it('Start Quiz', () => {
        cy.visit(url)
        cy.contains('Welcome')
        cy.contains('Start Quiz').click()
        cy.contains('Next')
        cy.contains('Restart')
    })
    it('Answer first question right', () => {
        cy.visit(url)
        cy.contains('Welcome')
        cy.contains('Start Quiz').click()
        cy.contains('CSS').click()
        cy.contains('Next').click()
        cy.contains('Your Answer is correct')
    })
    it('Answer first question wrong', () => {
        cy.visit(url)
        cy.contains('Welcome')
        cy.contains('Start Quiz').click()
        cy.contains('HTML').click()
        cy.contains('Next').click()
        cy.contains('Your answer is wrong')
    })
    it('should not advance with no answer selected', () => {
        cy.visit(url)
        cy.contains('Welcome')
        cy.contains('Start Quiz').click()
        cy.contains('Next').click()
    })
})
  