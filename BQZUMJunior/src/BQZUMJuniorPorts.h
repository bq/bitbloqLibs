/*
 * BQZUMJuniorPorts.h
 *
 * Copyright 2018 Alberto Valero <alberto.valero@bq.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#ifndef BQZUMJUNIORPORTS_H
#define BQZUMJUNIORPORTS_H

#define debug

namespace BQ{


//define port equivalences
#define A 5
#define B 6

class ZUMJuniorI2CPorts
{
	public:
	
	ZUMJuniorI2CPorts(int _p1, int _p2)
	{
		p1 = _p1;
		p2 = _p2;
	}	
	virtual ~ZUMJuniorI2CPorts(){}
	
	int p1, p2;
	
	const int operator[](size_t index) const{
		switch(index){
			case A:
				return p1;
				break;
			case B:
				return p2;
				break;
			default:
				return -1;
		}
	}
};


} //end namespace BQ

#endif
