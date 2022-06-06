using System.Collections;
using System.Collections.Generic;
using Lab3.model;
using Lab3.repository;

namespace Lab3_Csharp_Interfata.service
{
    public class ServiceOrganizator
    {
        private RepositoryOrganizator repoOrganizator;

        public ServiceOrganizator(RepositoryOrganizator repoOrganizator)
        {
            this.repoOrganizator = repoOrganizator;
        }

        public IEnumerable<Organizator> findAllOrganizatori()
        {
            return repoOrganizator.findAll();
        }
    }
}