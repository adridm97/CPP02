/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:00:37 by adrian            #+#    #+#             */
/*   Updated: 2024/10/20 14:59:37 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = n << _fractionalBits;
}
Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(f * (1 << _fractionalBits));
}

bool Fixed::operator>(const Fixed &other) const 
{
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const 
{
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const 
{
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const 
{
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const 
{
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const 
{
    return this->_fixedPointValue != other._fixedPointValue;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed Fixed::operator+(const Fixed &other) const 
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const 
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const 
{
    Fixed result;
    result.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const 
{
    Fixed result;
    result.setRawBits((this->_fixedPointValue << _fractionalBits) / other._fixedPointValue);
    return result;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &fixed)
        this->_fixedPointValue = fixed.getRawBits();
    return (*this);
}

Fixed& Fixed::operator++() 
{
    this->_fixedPointValue++;
    return *this;
}
Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;
}
Fixed& Fixed::operator--() 
{
    this->_fixedPointValue--;
    return *this;
}
Fixed Fixed::operator--(int) 
{
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) 
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) 
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) 
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) 
{
    return (a > b) ? a : b;
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
float Fixed::toFloat(void) const 
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}
int Fixed::toInt(void) const 
{
    return _fixedPointValue >> _fractionalBits;
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called." << std::endl;
}