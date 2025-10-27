/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:24:40 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/10/27 00:35:42 by gcesar-n         ###   ########.fr       */
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
	log("getRawBits member function called");
	return value_fixed_point;
}

void Fixed::setRawBits(int const raw)
{
	value_fixed_point = raw;
}

