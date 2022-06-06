using System;

namespace Lab3.model
{
    public class ParticipantDTO
    {
        private String nume;
        private String varsta;
        private String nrProbe;

        public ParticipantDTO(string nume, string varsta, string nrProbe)
        {
            this.nume = nume;
            this.varsta = varsta;
            this.nrProbe = nrProbe;
        }

        public String getNume()
        {
            return nume;
        }

        public String getVarsta()
        {
            return varsta;
        }

        public String getNrProbe()
        {
            return nrProbe;
        }
    }
}