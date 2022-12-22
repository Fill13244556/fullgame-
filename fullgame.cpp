#include "settings.h"
#include "functions.h"
using namespace sf;
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//создание объектов игры

	//ракетки
	RectangleShape leftbat, rightbat;
	initBat(leftbat, leftBatColor, leftBatStartPos);
	initBat(rightbat, rightBatColor, rightBatStartPos);
	float leftBatSpeedY = 0.f;
	float rightBatSpeedY = 0.f;

	//шарик
	CircleShape ball;
	initBall(ball, ballColor, ballPosition);

	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];

	//СЧЕТ
	int leftPlayerScore = 0;
	int rightPlayerScore = 0;

	Font font;
	font.loadFromFile("ds-digib.ttf");

	Text leftPlayerScoreText;
	initText(leftPlayerScoreText, leftPlayerScore, font, charSize, lefttextStartPos);

	//
	Text rightPlayerScoreText;
	initText(rightPlayerScoreText, rightPlayerScore, font, charSize, righttextStartPos);

	//Победный счёт 

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		//1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

		//Левая ракетка  
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			leftbat.move(0, -batDy);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftbat.move(0, batDy);
		}
		if (leftbat.getPosition().y < 0) {
			leftbat.setPosition(leftbat.getPosition().x, 0);
		}
		if (leftbat.getPosition().y + leftbat.getGlobalBounds().height > WINDOW_HEIGHT) {
			leftbat.setPosition(leftbat.getPosition().x, WINDOW_HEIGHT - leftbat.getGlobalBounds().height);
		}
		
		//Левая ракетка  
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			rightbat.move(0, -batDy);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			rightbat.move(0, batDy);
		}
		if (rightbat.getPosition().y < 0) {
			rightbat.setPosition(rightbat.getPosition().x, 0);
		}
		if (rightbat.getPosition().y + rightbat.getGlobalBounds().height > WINDOW_HEIGHT) {
			rightbat.setPosition(rightbat.getPosition().x, WINDOW_HEIGHT - rightbat.getGlobalBounds().height);
		}
		
		//2 Обновление объектов
		//шарик
		//движение шарика
		ball.move(ball_speedx, ball_speedy);
		if (ball.getPosition().x <= 0) {
			ball_speedx = -ball_speedx;
			rightPlayerScore += 1;
			rightPlayerScoreText.setString(std::to_string(rightPlayerScore));
		}
		if ((ball.getPosition().x + 2 * BALL_RADIUS) >= WINDOW_WIDTH)
		{
			ball_speedx = -ball_speedx;
			leftPlayerScore += 1;

			leftPlayerScoreText.setString(std::to_string(leftPlayerScore));
		}
		if (ball.getPosition().y <= 0 || ball.getPosition().y + 2 * BALL_RADIUS >= WINDOW_HEIGHT)
		{
			ball_speedy = -ball_speedy;
		}
		
		//двигаем ракетку  
		
		//и сразу обнуляем скорость
		
		// отбивание мяча ракетки 
		//вычисляем точки середины сторон описанного вокруг мяча квадрата. 
		float ballX = ball.getPosition().x; 
		float ballY = ball.getPosition().y; 
		Vector2f midTop { ballX+  BALL_RADIUS, ballY }; 
		Vector2f midLeft{ ballX, ballY + BALL_RADIUS };
		Vector2f midBottom{ ballX + BALL_RADIUS, ballY + 2 * BALL_RADIUS };
		Vector2f midRight{ ballX + 2 *  BALL_RADIUS, ballY + BALL_RADIUS };
		//Удар об левую ракетку 
		if (pointInRect(leftbat, midLeft)) ball_speedx = -ball_speedx;
		if (pointInRect(rightbat, midBottom) || pointInRect(leftbat, midTop))
			ball_speedy = -ball_speedy; 
		//Удар об правую ракетку 
		if (pointInRect(rightbat, midRight)) ball_speedx = -ball_speedx;
		if (pointInRect(rightbat, midBottom) || pointInRect(rightbat, midTop))
			ball_speedy = -ball_speedy;

		//3 Отрисовка окна
		//3.1 Очистка окна
		window.clear();
		//3.2 Отрисовка объектов (В ПАМЯТИ!)
		window.draw(leftbat);
		window.draw(rightbat);
		window.draw(ball);
		window.draw(leftPlayerScoreText);
		window.draw(rightPlayerScoreText);
		//3.3 вывод на экран
		window.display();
	}

	return 0;
}