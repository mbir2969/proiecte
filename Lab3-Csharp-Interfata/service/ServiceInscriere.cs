using System;
using System.Collections;
using System.Collections.Generic;
using Lab3.model;
using Lab3.repository;

namespace Lab3_Csharp_Interfata.service
{
    public class ServiceInscriere
    {
        private RepositoryInscriereDB repoInscriere;

        public ServiceInscriere(RepositoryInscriereDB repoInscriere)
        {
            this.repoInscriere = repoInscriere;
        }

        public IEnumerable<Inscriere> findAllInscrieri()
        {
            return repoInscriere.findAll();
        }

        public void adaugaInscriere(string numeParticipant, CategorieVarsta varsta, string nrProbe, Proba proba)
        {
            Organizator organizator = new Organizator("username", "password");
            Participant participant = new Participant(numeParticipant, varsta, Int32.Parse(nrProbe));
            Inscriere inscriere = new Inscriere(organizator, participant, proba);
            repoInscriere.add(inscriere);
        }

        public List<Inscriere> cautaParticipantiInscrieri(CategorieVarsta varsta, Proba proba)
        {
            List<Inscriere> inscrieriParticipantiCautati = new List<Inscriere>();
            foreach (Inscriere inscriere in repoInscriere.findAll())
            {
                if (varsta.Equals(CategorieVarsta.ZERO) && inscriere.getProba().Equals(proba))
                {
                    inscrieriParticipantiCautati.Add(inscriere);
                }

                if (proba.Equals(Proba.ZERO) && inscriere.getParticipant().getVarsta().Equals(varsta))
                {
                    inscrieriParticipantiCautati.Add(inscriere);
                }

                if (inscriere.getProba().Equals(proba) && inscriere.getParticipant().getVarsta().Equals(varsta))
                {
                    inscrieriParticipantiCautati.Add(inscriere);
                }
            }

            return inscrieriParticipantiCautati;
        }
    }
}