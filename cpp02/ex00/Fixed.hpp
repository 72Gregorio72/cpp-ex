#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		Fixed(const int intValue);
		Fixed(const float floatValue);
		float ToFloat( void ) const;
		int ToInt( void ) const;
		Fixed &operator<<(const Fixed &other);

		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif