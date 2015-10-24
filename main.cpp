#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
using namespace sf;
int main()
{
	cout << "basladi";
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	for (int k = 0; k < Joystick::Count; k++){
		bool connected = sf::Joystick::isConnected(k);
		if (connected){

			cout << endl << "Joystick : " << k << " connected ";
			cout << endl << " button count " << sf::Joystick::getButtonCount(k) << endl;
		}
	}



	while (window.isOpen())
	{
		for (int k = 0; k < Joystick::Count; k++){

			for (int i = 0; i < (Joystick::getButtonCount(k)); i++){
				if (sf::Joystick::isButtonPressed(k, i)){
					cout << endl << "Joystick" << k << ": button" << i << "pressed" << endl;
					//Joystick::getAxisPosition 	( 	unsigned int  	joystick,Axis  	axis)		
				}
				int AxisX = Joystick::getAxisPosition(k, Joystick::X);
				int AxisY = Joystick::getAxisPosition(k, Joystick::Y);

				if (AxisX <= 100 && AxisX >= -100 && AxisX != 0){
					cout << endl << "X : " << AxisX;
					if (AxisX > 0){
						cout << " saga";
					}
					else if (AxisX < 0){
						cout << " sola";
					}
				}
				if (AxisY <= 100 && AxisY >= -100 && AxisY != 0){
					cout << endl << "Y : " << AxisY;
					if (AxisY > 0){
						cout << " ileri";
					}
					else if (AxisY < 0){
						cout << " geri";
					}
				}
			}

		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}