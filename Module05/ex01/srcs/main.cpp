/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:56:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/28 03:03:19 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	std::cout << YELLOW "Create a bureaucrat and two forms" RESET << std::endl;
	Bureaucrat	bureaucrat("Michelle Obama", 16);
	Form		form("Form 1", 15, 20);
	Form		form2("Form 2", 150, 150);
	std::cout << std::endl;

	std::cout << YELLOW "Bureaucrat created:" RESET << std::endl;
	std::cout << bureaucrat << std::endl;
	
	std::cout << YELLOW "Forms created:" RESET << std::endl;	
	std::cout << form << std::endl;
	std::cout << form2 << std::endl << std::endl;

	std::cout << YELLOW "Bureaucrat tries to sign forms" RESET << std::endl;
	bureaucrat.signForm(form);
	bureaucrat.signForm(form2);
	std::cout << std::endl;
	std::cout << form << std::endl;
	std::cout << form2 << std::endl << std::endl;

	std::cout << YELLOW "Bureaucrat tries to execute forms" RESET << std::endl;
	bureaucrat.executeForm(form);
	bureaucrat.executeForm(form2);
	std::cout << std::endl;

	std::cout << YELLOW "New bureaucrat tries to execute forms" RESET << std::endl;
	Bureaucrat	bureaucrat2("Jean Castex", 120);
	std::cout << bureaucrat2;
	bureaucrat2.executeForm(form);
	bureaucrat2.executeForm(form2);
	std::cout << std::endl;
	
	std::cout << YELLOW "First bureaucrat tries to sign forms after being promoted" RESET << std::endl;
	bureaucrat.incrementGrade();
	std::cout << bureaucrat;
	bureaucrat.signForm(form);
	bureaucrat.signForm(form2);
	std::cout << std::endl;
	std::cout << form << std::endl;
	std::cout << form2 << std::endl;
	
	return 0;
}