/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:22:06 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/11/04 11:13:06 by gcesar-n         ###   ########.fr       */
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

		bool operator>(const Fixed& other)const;
		bool operator<(const Fixed& other)const;
		bool operator>=(const Fixed& other)const;
		bool operator<=(const Fixed& other)const;
		bool operator==(const Fixed& other)const;
		bool operator!=(const Fixed& other)const;

		Fixed operator+(const Fixed& other)const;
		Fixed operator-(const Fixed& other)const;
		Fixed operator*(const Fixed& other)const;
		Fixed operator/(const Fixed& other)const;

		Fixed& operator++(); 
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

void log(std::string message);
std::ostream& operator<<(std::ostream &outStream, Fixed const &parameter);


#endif