/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:06:22 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/11/04 22:13:30 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

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
    // log("Int constructor called");
    value_fixed_point = integerParameter * 256;
}

Fixed::Fixed(const float floatParameter)
{
    // log("Float constructor called");
    value_fixed_point = roundf(floatParameter * 256.0f);
    // std::cout << value_fixed_point << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	// log("Copy constructor called");
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// log("Copy assignment operator called");
	if (this != &other)
	{
		this->value_fixed_point = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	// log("Destructor called");
}

int Fixed::getRawBits() const
{
	// log("getRawBits member function called");
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

    result = value_fixed_point / 256;
    return result;
}

std::ostream& operator<<(std::ostream &outStream, Fixed const &parameter)
{
	outStream << parameter.toFloat();
	return outStream;
}

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
Fixed Fixed::operator+(const Fixed& other) const
{
    // Convert both to floats, add them,
    // and let the float constructor handle the conversion back.
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
