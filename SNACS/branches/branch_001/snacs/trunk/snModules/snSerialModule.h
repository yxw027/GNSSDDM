/*
 *  SNACS - The Satellite Navigation Radio Channel Simulator
 *
 *  Copyright (C) 2009  F. M. Schubert
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * \file snSerialModule.h
 *
 * \author Frank Schubert
 */

#ifndef SNSERIALMODULE_H
#define SNSERIALMODULE_H

#include "snConsumingModule.h"
#include "../snSimulation/ConcurrentBuffer3.h"
/**
 * \brief class for serialization of the snBlocks class
 */
class snSerialModule: public snConsumingModule {
Q_OBJECT
public:

	/**
	 * \brief snBlockSerial constructor
	 */
	snSerialModule(SNSignal pSNSignal, ConcBuf3* _circbuf);

	/**
	 * \brief returns the absolute amount of processed samples
	 */
	Samples_Type get_absolute_sample() const {
		return absoluteSample;
	}

private:

	itpp::cvec serBuf; ///< for an array that serializes the data coming from a concBuf
	Samples_Type serbuf_last_sample, serbuf_actual_sample, SerBufSize;
	int SerBufStatus;
	bool stop_when_empty;
	long cBufSmpls, maxBufSmpls;
	bool serbuf_initialized;
	Samples_Type absoluteSample;
	Blocks_Type akt_blocks;

protected:

	/**
	 * \brief returns the next n samples
	 */
	itpp::cvec get_next_samples(Samples_Type n);

	/**
	 * \brief initializes the serial buffer. Should be called by snBlocks in their constructor.
	 */
	void InitSerialBuffer(Samples_Type size);

	/**
	 * \brief allows to go back to a specific samples position in the actual serial buffer
	 */
	void set_next_sample_index(Samples_Type index);
};

#endif
