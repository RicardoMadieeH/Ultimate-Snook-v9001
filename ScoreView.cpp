#include "ScoreView.h"

ScoreView::ScoreView(Snake &b) :body(b) {
	if (!font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf")) {
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
			abort();
		}
	}

	koniec.setBackColor(sf::Color::Black);
	koniec.setFont(font);
	koniec.setTextColor(sf::Color::White);
	koniec.sizeSet(sf::Vector2f(300, 50));
	koniec.setPosition(sf::Vector2f(250, 0));


	yS.setFillColor(sf::Color::White);
	yS.setCharacterSize(40);
	yS.setString("Your score: ");
	yS.setPosition(sf::Vector2f(175, 150));
	yS.setFont(font);

	hS.setFillColor(sf::Color::White);
	hS.setCharacterSize(40);
	hS.setString("Highest score: ");
	hS.setPosition(sf::Vector2f(175, 200));
	hS.setFont(font);

	yourScore.setFont(font);
	yourScore.setCharacterSize(40);
	yourScore.setFillColor(sf::Color::White);
	yourScore.setPosition(sf::Vector2f(400, 150));

	highScore.setFont(font);
	highScore.setCharacterSize(40);
	highScore.setFillColor(sf::Color::White);
	highScore.setPosition(sf::Vector2f(450, 200));

	tryAgain.setBackColor(sf::Color(180, 180, 180));
	tryAgain.setFont(font);
	tryAgain.sizeSet(sf::Vector2f(200, 200));
	tryAgain.setTextString("Try Again", 40);
	tryAgain.setTextColor(sf::Color::Black);
	tryAgain.setOutline(2, sf::Color::Yellow);
	tryAgain.setPosition(sf::Vector2f(100, 350));
	tryAgain.setTextPosition(sf::Vector2f(117, 420));

	exit.setBackColor(sf::Color(180, 180, 180));
	exit.setFont(font);
	exit.sizeSet(sf::Vector2f(200, 200));
	exit.setTextString("Exit", 60);
	exit.setTextColor(sf::Color::Black);
	exit.setOutline(2, sf::Color::Yellow);
	exit.setPosition(sf::Vector2f(1000, 350));
	exit.setTextPosition(sf::Vector2f(1047, 410));
}

void ScoreView::draw(sf::RenderWindow &win) {
	if (body.getStateOfGame() == FINISHED_LOSS){
		koniec.setTextString("PRZEGRALES", 45);
		koniec.setTextPosition(sf::Vector2f(470, -5));
	}
	else if (body.getStateOfGame() == FINISHED_WIN) {
		koniec.setTextString("WYGRALES", 45);
		koniec.setTextPosition(sf::Vector2f(500, -5));
	}

	koniec.drawTo(win);

	setScore();

	win.draw(yS);
	win.draw(hS);

	endScore = (int)body.getLength() - 2;

	scoreString = std::to_string(endScore);
	yourScore.setString(scoreString);
	win.draw(yourScore);

	highscoreString = std::to_string(bestScore);
	highScore.setString(highscoreString);
	win.draw(highScore);

	tryAgain.drawTo(win);
	exit.drawTo(win);
}

void ScoreView::setScore() {
	std::fstream highscore;
	highscore.open("highscores.txt", std::ios::in /*| std::ios::out | std::ios::trunc*/);

	if (!highscore) {
		highscore.close();
		std::ofstream temp("highscores.txt");
		temp << 0 << std::endl;
		temp.close();
		highscore.open("highscores.txt", std::ios::in /*| std::ios::out | std::ios::trunc*/);
	}

	std::string line;

	std::getline(highscore, line);

	std::istringstream kopytko(line);

	kopytko >> bestScore;

	highscore.close();

	if (bestScore < endScore) {
		highscore.open("highscores.txt", std::ios::trunc);
		highscore.close();
		highscore.open("highscores.txt", std::ios::out);
		highscore << scoreString;
		highscore.close();
	}
}










