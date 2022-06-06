using System;
using System.Collections;
using System.Collections.Generic;
using Lab3.model;
using Lab3.repository;

namespace Lab3_Csharp_Interfata.service
{
    public class Service
    {
        private ServiceParticipant serviceParticipant;
        private ServiceOrganizator serviceOrganizator;
        private ServiceInscriere serviceInscriere;

        public Service(ServiceParticipant serviceParticipant, ServiceOrganizator serviceOrganizator, ServiceInscriere serviceInscriere)
        {
            this.serviceParticipant = serviceParticipant;
            this.serviceOrganizator = serviceOrganizator;
            this.serviceInscriere = serviceInscriere;
        }

        public IEnumerable<Participant> findAllParticipanti()
        {
            return serviceParticipant.findAllParticipanti();
        }

        public IEnumerable<Inscriere> findAllInscrieri()
        {
            return serviceInscriere.findAllInscrieri();
        }

        public Organizator verificaCredentialele(String username, String password)
        {
            IEnumerable<Organizator> organizatori = serviceOrganizator.findAllOrganizatori();
            foreach (Organizator organizator in organizatori)
            {
                if (organizator.getUserName().Equals(username) && organizator.getPassword().Equals(password))
                {
                    return organizator;
                }
            }
            return null;
        }

        public void inscriereParticipant(string numeParticipant, CategorieVarsta varsta, string nrProbe, Proba proba)
        {
            serviceParticipant.adaugaParticipant(numeParticipant, varsta, nrProbe);
            serviceInscriere.adaugaInscriere(numeParticipant, varsta, nrProbe, proba);
        }

        public List<Inscriere> cautaParticipanti(CategorieVarsta varsta, Proba proba)
        {
            return serviceInscriere.cautaParticipantiInscrieri(varsta, proba);
        }
    }
}