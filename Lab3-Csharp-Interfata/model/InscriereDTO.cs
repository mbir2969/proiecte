using System;

namespace Lab3.model
{
    public class InscriereDTO
    {
        private int idInscriere;
        private String numeParticipant;
        private String varstaParticipant;
        private String proba;

        public InscriereDTO(int idInscriere, string numeParticipant, string varstaParticipant, string proba)
        {
            this.idInscriere = idInscriere;
            this.numeParticipant = numeParticipant;
            this.varstaParticipant = varstaParticipant;
            this.proba = proba;
        }

        public int getIdInscriere()
        {
            return idInscriere;
        }

        public String getNumeParticipant()
        {
            return numeParticipant;
        }

        public String getVarstaParticipant()
        {
            return varstaParticipant;
        }

        public String getProba()
        {
            return proba;
        }
        
        
    }
}