#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "linkedList.h"

#define CP 1251
#define textSize 10

void setShapes(Node *head, sf::CircleShape *shapes, int n) {
	for (int i = 0; i < n; i++) {
		shapes[i].setRadius(head->p.r);
		shapes[i].setPosition(head->p.x, head->p.y);
		shapes[i].setFillColor(sf::Color::White);
		head = head->next;
	}
}


void setText(sf::CircleShape *shapes, sf::RenderWindow &window, int n) {
	sf::Font font;
	if (!font.loadFromFile("Roboto-Regular.ttf")) { /*error...*/ }
	sf::Text text;
	text.setCharacterSize(textSize);
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	int r;
	char c;
	for (int i = 0; i < n; i++) {
		r = shapes[i].getRadius();
		c = i + '0';
		text.setString(c);
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
		text.setPosition(shapes[i].getPosition().x + r, shapes[i].getPosition().y + r);
		window.draw(text);
	}
}


void drawCircleShapes(sf::CircleShape *shapes, sf::RenderWindow &window, int n) {
	for (int i = 0; i < n; i++) {
		window.draw(shapes[i]);
	}
}


void draw(int x0, int y0, int x1, int y1, sf::VertexArray line, sf::RenderWindow &window) {
	sf::Vector2u size = window.getSize();//получение вектора текущего размера окна
	line[0].position = sf::Vector2f(x0, y0);//позици€ начала линии - в центре окна
	line[1].position = sf::Vector2f(x1, y1); //конец линии - в текущих координатах xi и yi
	window.draw(line);//вывод линии в буфер
}


void connectCircles(sf::CircleShape *shapes, sf::RenderWindow &window, int n) {
	sf::VertexArray line(sf::Lines, 2);
	int x0, y0, x1, y1, r1, r2;
	for (int i = 0; i < n - 1; i++) {
		r1 = shapes[i].getRadius();
		r2 = shapes[i + 1].getRadius();
		x0 = shapes[i].getPosition().x + r1;
		y0 = shapes[i].getPosition().y + r1;
		x1 = shapes[i + 1].getPosition().x + r2;
		y1 = shapes[i + 1].getPosition().y + r2;
		std::cout << x0 << "\n";
		draw(x0, y0, x1, y1, line, window);
	}
}


int main()
{
	SetConsoleCP(CP);
	SetConsoleOutputCP(CP);

	Point p = { width / 2, height / 2, 10 }; // just hardcoded first position
	Node *head = new Node;
	head->p = p;
	head->next = NULL;
	createRandomList(head, N);
	printList(head);


	sf::RenderWindow window(sf::VideoMode(width, height), "linked list");

	sf::Event event;

	sf::CircleShape shapes[N];
	sf::VertexArray lines[N - 1];

	setShapes(head, shapes, N);

	drawCircleShapes(shapes, window, N);
	connectCircles(shapes, window, N);
	setText(shapes, window, N);
	window.display();

	int del;
	std::cout << "\n¬ведите номер круга дл€ удалени€ ::\n";
	std::cin >> del;
	if (del < N && del >= 0) {
		std::cout << del;
	}
	else {
		std::cout << "Ќет такого номера!\n";
	}
	deleteNth(&head, del);
	printList(head);

	sf::RenderWindow newWindow(sf::VideoMode(width, height), "linked list after deletion");
	sf::CircleShape shapes1[N - 1];
	sf::VertexArray lines1[N - 2];

	setShapes(head, shapes1, N - 1);

	drawCircleShapes(shapes1, newWindow, N - 1);
	connectCircles(shapes1, newWindow, N - 1);
	setText(shapes1, newWindow, N - 1);
	newWindow.display();

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
		}
	}
	return 0;
}
