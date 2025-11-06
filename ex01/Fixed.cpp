/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:24:40 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/11/06 12:12:06 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

void log(std::string message)
{
	std::cout << message << std::endl;
}

Fixed::Fixed()
{
	log("Default constructor called");
	value_fixed_point = 0;
}

Fixed::Fixed(const int integerParameter)
{
	log("Int constructor called");
	value_fixed_point = integerParameter << bits;
}

Fixed::Fixed(const float floatParameter)
{
	log("Float constructor called");
	value_fixed_point = roundf(floatParameter * (1 << bits));
}	

Fixed::Fixed(const Fixed& other)
{
	log("Copy constructor called");
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	log("Copy assignment operator called");
	if (this != &other)
	{
		this->value_fixed_point = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	log("Destructor called");
}

int Fixed::getRawBits() const
{
	return (value_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	value_fixed_point = raw;
}

float Fixed::toFloat(void) const
{
	const float scalingFactor = 256.0f;
	float floatValue = 0;
	float result = 0;

	floatValue = static_cast<float>(this->value_fixed_point);
	result = (floatValue / scalingFactor);
	return result;
}

int Fixed::toInt() const
{
	int result = 0;

	result = value_fixed_point >> bits;
	return result;
}

std::ostream& operator<<(std::ostream &outStream, Fixed const &parameter)
{
	outStream << parameter.toFloat();
	return (outStream);
}
