using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3.model
{
    public class Inscriere : Identifiable<int>
    {
        private int id;
        private Organizator organizator;
        private Participant participant;
        private Proba proba;

        public Inscriere(Organizator organizator, Participant participant, Proba proba)
        {
            this.organizator = organizator;
            this.participant = participant;
            this.proba = proba;
        }


        public int getID()
        {
            return id;
        }


        public Organizator getOrganizator()
        {
            return organizator;
        }

        public Participant getParticipant()
        {
            return participant;
        }

        public Proba getProba()
        {
            return proba;
        }
        public void setID(int id)
        {
            this.id = id;
        }


        public void setOrganizator(Organizator organizatorNou)
        {
            organizator = organizatorNou;
        }

        public void setParticipant(Participant participantNou)
        {
            participant = participantNou;
        }

        public void setProba(Proba probaNoua)
        {
            proba = probaNoua;
        }

        protected bool Equals(Inscriere other)
        {
            return id == other.id && Equals(organizator, other.organizator) && Equals(participant, other.participant) && proba == other.proba;
        }

        public override bool Equals(object obj)
        {
            if (ReferenceEquals(null, obj)) return false;
            if (ReferenceEquals(this, obj)) return true;
            if (obj.GetType() != this.GetType()) return false;
            return Equals((Inscriere) obj);
        }

        public override int GetHashCode()
        {
            unchecked
            {
                var hashCode = id;
                hashCode = (hashCode * 397) ^ (organizator != null ? organizator.GetHashCode() : 0);
                hashCode = (hashCode * 397) ^ (participant != null ? participant.GetHashCode() : 0);
                hashCode = (hashCode * 397) ^ (int) proba;
                return hashCode;
            }
        }

        public override string ToString()
        {
            return "Inscriere{" +
                   "participant=" + participant +
                   ", organizator=" + organizator +
                   ", proba=" + proba +
                   '}';
        }
        
        
    }
}
