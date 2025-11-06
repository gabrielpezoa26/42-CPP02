/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:06:22 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/11/06 12:08:24 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

const int Fixed::bits = 8;

void log(std::string message)
{
	std::cout << message << std::endl;
}

/* ============= OOP utilities ============= */
Fixed::Fixed()
{
	value_fixed_point = 0;
}

Fixed::Fixed(const int integerParameter)
{
	value_fixed_point = integerParameter * 256;
}

Fixed::Fixed(const float floatParameter)
{
	value_fixed_point = roundf(floatParameter * 256.0f);
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->value_fixed_point = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	
}

/* ============= getter and setter ============= */
int Fixed::getRawBits() const
{
	return (value_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	value_fixed_point = raw;
}

/* ============= conversion functions ============= */
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

	result = value_fixed_point / 256;
	return result;
}

/* ============= assign operator overload ============= */
std::ostream& operator<<(std::ostream &outStream, Fixed const &parameter)
{
	outStream << parameter.toFloat();
	return outStream;
}

/* ============= comparison operators ============= */

bool Fixed::operator>(const Fixed& other)const
{
	return (value_fixed_point > other.value_fixed_point);
}

bool Fixed::operator<(const Fixed& other)const
{
	return (value_fixed_point < other.value_fixed_point);
}

bool Fixed::operator>=(const Fixed& other)const
{
	return (value_fixed_point >= other.value_fixed_point);
}

bool Fixed::operator<=(const Fixed& other)const
{
	return (value_fixed_point <= other.value_fixed_point);
}

bool Fixed::operator==(const Fixed& other)const
{
	return (value_fixed_point == other.value_fixed_point);
}

bool Fixed::operator!=(const Fixed& other)const
{
	return (value_fixed_point != other.value_fixed_point);
}

/* ============= arithmetic operators ============= */

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

/* ============= increment && decrement operators ============= */
Fixed& Fixed::operator++()
{
	this->value_fixed_point++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed& Fixed::operator--()
{
	this->value_fixed_point--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return temp;
}

/* ============= utility functions ============= */
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}
