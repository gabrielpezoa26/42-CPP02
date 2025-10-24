/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:21:53 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/10/24 12:47:57 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : value_fixed_point(0), bits(8)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : bits(other.bits)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value_fixed_point = other.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator	 called" << std::endl;
	if (this != &other)
	{
		this->value_fixed_point = other.getRawBits();
	}
	return (*this);
}

Fixed::getRawBits(void) const
{
	std::cout << "GetRawBits member function called" << std::endl;
	return value_fixed_point;
}

Fixed::setRawBits(int const raw)
{
	value_fixed_point = raw;
}
