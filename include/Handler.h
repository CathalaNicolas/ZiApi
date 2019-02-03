#pragma once
/**
 * \file      Handler.h
 * \version   1.0
 * \brief     Definit la classe Handler
 *
 * \details    Le handler se charge d'enregistrer les modules,
 *			   orchestre les evenements. La requete HTTP ainsi
 *			   que sa reponse sont stockees dans le handler.
 */
#include "IModule.h"
#include "Event.h"
#include <list>

namespace ZiApi
{
	class IModule;

	class Handler
	{
	public:
		/**
		* \brief      Constructeur de la classe Handler
		* \details    Creer un Handler avec une requete et une reponse vide.
		*
		*
		* \return    Un \e Handler
		 */
		Handler();
		~Handler();

		/**
		* \brief      Getter des modules enregistres.
		* \details    Fonction permettant d'acceder a la liste de module enregistre.
		*			  
		*
		* \return    Une \e list de module
		 */
		std::list<IModule*>	getModules()const;
		/**
		* \brief      Getter de la requete HTTP.
		* \details    Fonction permettant d'acceder a la requete HTTP.
		*
		*
		* \return    Une \e HttpMessage contenant la requete HTTP.
		 */
		HttpMessage			getRequest()const;
		/**
		* \brief      Getter de la reponse HTTP.
		* \details    Fonction permettant d'acceder a la reponse HTTP.
		*
		*
		* \return    Une \e HttpMessage contenant la reponse HTTP.
		 */
		HttpMessage			getResponse()const;
		/**
		* \brief      Setter de la requete HTTP.
		* \details    Fonction permettant de modifier la requete HTTP.
		*
		* \param request	Une string correspondant a la requete HTTP.
		 */
		void				setRequest(const std::string &request);
		/**
		* \brief      Setter de la reponse HTTP.
		* \details    Fonction permettant de modifier la reponse HTTP.
		*
		* \param request	Une string correspondant a la reponse HTTP.
		 */
		void				setResponse(const std::string &response);
		
		/**
		* \brief      Enregistre le module.
		* \details    Fonction permettant d'enregistrer le module
		*			  dans la liste des modules du \e Handler
		*
		* \param Module	Un pointeur sur le module a ajouter a la liste.
		 */
		void				registerModule(IModule *module);
		/**
		* \brief      Lance les modules en fonction de leur \e AnchorPoint
		* \details    Fonction permettant de lancer la cha�ne de module
		*			  correspondant au type de point d'ancrage.
		*
		* \param AnchorPoint	Un point d'ancrage.
		 */
		void				launchTypeModule(const Event::AnchorPoint &anchorPoint);

	private:
		std::list<IModule*> listModule;
		HttpMessage			request;
		HttpMessage			response;
		std::list<std::function<void(HttpMessage&, HttpMessage&)>>	getListFunction(const std::list<IModule*> listModule, const Event::AnchorPoint &anchorPoint);
		std::list<Event>											getAllModuleEvent(const std::list<IModule*> listModule, const Event::AnchorPoint &anchorPoint);
	};
}