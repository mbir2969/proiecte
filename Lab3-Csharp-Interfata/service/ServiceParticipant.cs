using System;
using System.Collections;
using System.Collections.Generic;
using Lab3.model;
using Lab3.repository;

namespace Lab3_Csharp_Interfata.service
{
    public class ServiceParticipant
    {
        private RepositoryParticipantDB repoParticipant;

        public ServiceParticipant(RepositoryParticipantDB repoParticipant)
        {
            this.repoParticipant = repoParticipant;
        }

        public IEnumerable<Participant> findAllParticipanti()
        {
            return repoParticipant.findAll();
        }

        public void adaugaParticipant(string numeParticipant, CategorieVarsta varsta, string nrProbe)
        {
            Participant participant = new Participant(numeParticipant, varsta, Int32.Parse(nrProbe));
            repoParticipant.add(participant);
        }
    }
}