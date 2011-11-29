/*******************************************************************
This file is part of Damaris.

Damaris is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Damaris is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Damaris.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/
/**
 * \file Environment.hpp
 * \date October 2011
 * \author Matthieu Dorier
 * \version 0.3
 */

#include "common/Debug.hpp"
#include "common/Environment.hpp"

namespace Damaris {

	Environment* Environment::m_instance = NULL;

	Environment::Environment(std::auto_ptr<Model::simulation_mdl> mdl, int pid)
	{
		model = mdl;
		id = pid;
	}

	Environment* Environment::getInstance()
	{
		return m_instance;
	}

	void Environment::initialize(std::auto_ptr<Model::simulation_mdl> mdl, int pid)
	{
		if(m_instance) {
			WARN("Environment already initialized.");
			return;
		}
		m_instance = new Environment(mdl,pid);
	}

	void Environment::finalize()
	{
		if(m_instance == NULL) {
			WARN("Environment already finalized.");
			return;
		}
		delete m_instance;
	}
}
