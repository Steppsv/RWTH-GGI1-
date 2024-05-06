#pragma once

#include "vertagt_aktion.h"
#include <memory>
#include <vector>
#include <list>


namespace vertagt
{
	template <class T>
	class VListe
	{
	private:
		std::list<T> p_objekte;
		std::list<std::unique_ptr<VAktion<T>>> p_aktionen;

	public:
		// Typdefinitionen
		using iterator = typename std::list<T>::iterator;
		using const_iterator = typename std::list<T>::const_iterator;

		// Konstruktoren
		VListe() = default; // Benötigt man einen Standardkonstruktor?
		// Destruktor
		~VListe()
		{
			vAktualisieren();
			p_objekte.clear();
		}

		void clear()
		{
			p_objekte.clear();
		}

		// Lesefunktionen
		iterator next(iterator it)
		{
		   if (it != p_objekte.end()) {
		            ++it;  // Move to the next element
		        }

		    return it;
		}

		// Lesefunktionen
		const_iterator begin() const
		{
			return p_objekte.begin();
		}
		const_iterator end() const
		{
			return p_objekte.end();
		}
		iterator begin()
		{
			return p_objekte.begin();
		}
		iterator end()
		{
			return p_objekte.end();
		}
		bool empty() const
		{
			return p_objekte.begin() == nullptr;
		}

		// Schreibfunktionen
		void push_back(T obj)
		{
			auto pushbackAction = std::make_unique<VPushBack<T>>(p_objekte, move(obj));
									            p_aktionen.push_back(std::move(pushbackAction));
		}

		void push_front(T obj)
		{
			auto pushfrontAction = std::make_unique<VPushFront<T>>(p_objekte, move(obj));
						            p_aktionen.push_back(std::move(pushfrontAction));
		}

		void erase(iterator it)
		{
			auto eraseAction = std::make_unique<VErase<T>>(p_objekte, it);
			            p_aktionen.push_back(std::move(eraseAction));

		}

		// Änderungen auf Objektliste übertragen
		void vAktualisieren()
		{
			// Änderungen auf Objektliste übertragen
			for (auto& pAktion : p_aktionen)
			{
				// Aktion ausführen
				pAktion->vAusfuehren();
			}
			// Aktionsliste löschen
			p_aktionen.clear();
		}
	};
} // namespace vertagt
