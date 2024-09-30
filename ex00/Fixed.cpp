/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:00:37 by adrian            #+#    #+#             */
/*   Updated: 2024/09/30 09:24:07 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}
Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &fixed)
        this->_fixedPointValue = fixed.getRawBits();
    return (*this);
}
int Fixed::getRawBits() const
{
    std::cout << "getRawBits memer function called." << std::endl;
    return (this->_fixedPointValue);
}
void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called." << std::endl;
}