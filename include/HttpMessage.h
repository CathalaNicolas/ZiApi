/**
 * \file      HttpMessage.h
 * \version   1.0
 * \brief     Definit la classe HttpMessage
 *
 * \details    Un HttpMessage contient le header ainsi que le body
 *			   d'une requete/reponse.
 *
 */
#pragma once

#include "HttpField.h"
#include <string>

namespace ZiApi 
{
	class HttpMessage
	{
	public:
		/**
		* \brief      Constructeur par defaut de la classe HttpMessage
		* \details    Creer un HttpMessage avec un header et un body vide
		* \return    Un \e HttpMessage.
		 */
		HttpMessage() {};
		/**
		* \brief      Constructeur de la classe HttpMessage
		* \details    Creer un HttpMessage avec un header et un body,
		*			  et parse les string pour recuperer les champs
		*			  et les valeurs
		*
		* \param    header		String correspondant au header
		* \param    function    String correspondant au body
		* \return    Un \e HttpMessage
		 */
		HttpMessage(const std::string &header, const std::string &body);
		/**
		* \brief      Constructeur de la classe HttpMessage
		* \details    Creer un HttpMessage avec un header et un body
		*
		* \param    header		Un HttpField correspondant au header
		* \param    body		Un HttpField correspondant au body
		* \return    Un \e HttpMessage
		 */
		HttpMessage(const HttpField &header, const HttpField &body);

		/**
		* \brief      Constructeur de la classe HttpMessage
		* \details    Constructeur qui parse une requete/reponse pour
		*			  recuperer son header, son body et recuperer leurs
		*			  champs et leurs valeurs associees.
		*
		* \return    Un \e HttpField.
		 */
		HttpMessage(const std::string &message);
		~HttpMessage();

		/**
		* \brief      Getter du header
		* \details    Fonction donnant acces a l'objet HttpField contenant
		*			  le header
		*
		* \return    Un \e HttpField correspondant au header.
		 */
		HttpField	getHeader()const;
		/**
		* \brief      Getter du body
		* \details    Fonction donnant acces a l'objet HttpField contenant
		*			  le body
		*
		* \return    Un \e HttpField correspondant au body.
		 */
		HttpField	getBody()const;

	private:
		HttpField	header;
		HttpField	body;

		void		setHeader(const std::string &header);
		void		setBody(const std::string &body);
	};

}