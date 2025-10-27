/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:19:40 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/10/27 12:21:49 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value_fixed_point;
		static const int bits;


	public:
		Fixed();
		Fixed(const int integerParameter);
		Fixed(const float floatParameter);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw);
		int toInt( void ) const;
		float toFloat( void ) const;
		//operator overload()
};

void log(std::string message);


#endif


// The previous exercise was a good start, but our class is pretty useless. It can only
// represent the value 0.0.
// Add the following public constructors and public member functions to your class:

// 	• A constructor that takes a constant integer as a parameter.
// 	It converts it to the corresponding fixed-point value. The fractional bits value
// 	should be initialized to 8, like in exercise 00.       ok
		
// 	• A constructor that takes a constant floating-point number as a parameter.
// 	It converts it to the corresponding fixed-point value. The fractional bits value
// 	should be initialized to 8, like in exercise 00.      ok
		
// 	• A member function float toFloat( void ) const;
// 	that converts the fixed-point value to a floating-point value.
		
// 	• A member function int toInt( void ) const;
// 	that converts the fixed-point value to an integer value.

// 	And add the following function to the Fixed class files:
// 	• An overload of the insertion («) operator that inserts a floating-point representation
// 	of the fixed-point number into the output stream object passed as a parameter