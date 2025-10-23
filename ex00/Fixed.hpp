/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:19:12 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/10/23 17:33:00 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int value_fixed_point;
		const int bits;


	public:
		Fixed();
		Fixed(const Fixed&);
		// operator overload
		~Fixed();


		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif


/*
	Crie uma classe na Forma Canônica Ortodoxa que representa um número de ponto
	fixo:

	• Membros privados:
		◦ Um inteiro para armazenar o valor do número de ponto fixo.         ok
		◦ Um inteiro constante estático para armazenar o número de bits fracionários. 
		 	Seu valor sempre será o literal inteiro 8.           ok


	• Membros públicos:
		◦ Um construtor padrão que inicializa o valor do número de ponto fixo para 0.
		◦ Um construtor de cópia.
		◦ Uma sobrecarga do operador de atribuição de cópia.
		◦ Um destrutor.

		◦ Uma função de membro int getRawBits( void ) const;
		que retorna o valor bruto do valor de ponto fixo.
		◦ Uma função de membro void setRawBits( int const raw );
		que define o valor bruto do número de ponto fixo.
*/