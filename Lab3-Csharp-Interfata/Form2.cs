using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data.Entity.Core.Metadata.Edm;
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using Lab3.model;
using Lab3_Csharp_Interfata.service;

namespace Lab3_Csharp_Interfata
{
    public partial class Form2 : Form
    {
        private Service service;
        private readonly BindingList<InscriereDTO> inscrieri = new BindingList<InscriereDTO>();
        private readonly BindingList<ParticipantDTO> participantiCautati = new BindingList<ParticipantDTO>();

        private void initializeListaInscrieri()
        {
            inscrieri.Clear();
            foreach (Inscriere inscriere in service.findAllInscrieri())
            {
                CategorieVarsta varstaDB = inscriere.getParticipant().getVarsta();
                String varstaStr = null;
                if (varstaDB.Equals(CategorieVarsta.SIX_EIGHT))
                {
                    varstaStr = "6-8 ani";
                }
                else if (varstaDB.Equals(CategorieVarsta.NINE_ELEVEN))
                {
                    varstaStr = "9-11 ani";
                }
                else
                {
                    varstaStr = "12-15 ani";
                }

                Proba probaDB = inscriere.getProba();
                String probaStr = null;
                if (probaDB.Equals(Proba.FIFTY))
                {
                    probaStr = "50 m";
                }else if (probaDB.Equals(Proba.ONE_HUNDRED))
                {
                    probaStr = "100 m";
                }else if (probaDB.Equals(Proba.ONE_THOUSAND))
                {
                    probaStr = "1000 m";
                }
                else
                {
                    probaStr = "1500 m";
                }

                InscriereDTO inscriereDTO = new InscriereDTO(inscriere.getID(), inscriere.getParticipant().getNume(),
                    varstaStr, probaStr);
                inscrieri.Add(inscriereDTO);
            }
        }

        private void initializeListaParticipantiCautati(List<Inscriere> inscrieriParticipantiCautati)
        {
            participantiCautati.Clear();
            foreach (Inscriere inscriere in inscrieriParticipantiCautati )
            {
                CategorieVarsta varstaDB = inscriere.getParticipant().getVarsta();
                String varstaStr = null;
                if (varstaDB.Equals(CategorieVarsta.SIX_EIGHT))
                {
                    varstaStr = "6-8 ani";
                }
                else if (varstaDB.Equals(CategorieVarsta.NINE_ELEVEN))
                {
                    varstaStr = "9-11 ani";
                }
                else
                {
                    varstaStr = "12-15 ani";
                }
                ParticipantDTO participantDTO = new ParticipantDTO(inscriere.getParticipant().getNume(), varstaStr,
                    inscriere.getParticipant().getNumarProbe().ToString());
                participantiCautati.Add(participantDTO);
            }
        }

        private void initTabelInscrieri()
        {
            dataGridViewInscrieri.Rows.Clear();
            foreach (InscriereDTO inscriereDTO in inscrieri)
            {
                dataGridViewInscrieri.Rows.Add(inscriereDTO.getIdInscriere().ToString(),
                    inscriereDTO.getNumeParticipant(), inscriereDTO.getVarstaParticipant(), inscriereDTO.getProba());
            }
            completareNrParticicaptiPerProba();
        }

        private void initTabelParticipantiCautati()
        {
            dataGridViewParticipantiCautati.Rows.Clear();
            foreach (ParticipantDTO participantDTO in participantiCautati)
            {
                dataGridViewParticipantiCautati.Rows.Add(participantDTO.getNume(), participantDTO.getVarsta(),
                    participantDTO.getNrProbe());
            }
        }
        
        public Form2(Service service)
        {
            InitializeComponent();
            this.service = service;
            this.initializeListaInscrieri();
            this.initTabelInscrieri();
            this.completareNrParticicaptiPerProba();
        }
        

        private void logOutButton_Click(object sender, EventArgs e)
        {
            var form1 = new Form1(this.service);
            form1.Show();
            this.Hide();
        }

        private void butonInscriereParticipant_Click(object sender, EventArgs e)
        {
            String numeParticipant = textBoxAdaugareNume.Text;
            if (numeParticipant.Equals(""))
            {
                MessageBox.Show("Nu ati introdus numele participantului.");
                return;
            }
            String nrProbe = textBoxAdaugareNrProbe.Text;
            if (nrProbe.Equals(""))
            {
                MessageBox.Show(
                    "Nu ati introdus niciun numar de probe. Un participant poate participa la 1 sau 2 probe.");
                return;
            }
            CategorieVarsta varsta = CategorieVarsta.ZERO;
            if (sixEightCheckBox.Checked)
            {
                varsta = CategorieVarsta.SIX_EIGHT;
            }else if (nineElevenCheckBox.Checked)
            {
                varsta = CategorieVarsta.NINE_ELEVEN;
            }else if (twelveFifteenCheckBox.Checked)
            {
                varsta = CategorieVarsta.TWELVE_FIFTEEN;
            }
            else
            {
                MessageBox.Show("Nu ati ales nicio categorie de varsta!");
                return;
            }
            Proba proba = Proba.ZERO;
            if (fiftyCheckBox.Checked)
            {
                proba = Proba.FIFTY;
            }else if (oneHundreadCheckBox.Checked)
            {
                proba = Proba.ONE_HUNDRED;
            }else if (oneThousandCheckBox.Checked)
            {
                proba = Proba.ONE_THOUSAND;
            }else if (fiftyHundreadCheckBox.Checked)
            {
                proba = Proba.FIFTEEN_HUNDRED;
            }
            else
            {
                MessageBox.Show("Nu ati selectat nicio proba!");
                return;
            }
            
            service.inscriereParticipant(numeParticipant, varsta, nrProbe, proba);
            this.initializeListaInscrieri();
            this.initTabelInscrieri();
        }


        private void butonCautareParticipanti_Click(object sender, EventArgs e)
        {
            CategorieVarsta varsta = CategorieVarsta.ZERO;
            if (sixEightCheckBox.Checked)
            {
                varsta = CategorieVarsta.SIX_EIGHT;
            }else if (nineElevenCheckBox.Checked)
            {
                varsta = CategorieVarsta.NINE_ELEVEN;
            }else if (twelveFifteenCheckBox.Checked)
            {
                varsta = CategorieVarsta.TWELVE_FIFTEEN;
            }
            Proba proba = Proba.ZERO;
            if (fiftyCheckBox.Checked)
            {
                proba = Proba.FIFTY;
            }else if (oneHundreadCheckBox.Checked)
            {
                proba = Proba.ONE_HUNDRED;
            }else if (oneThousandCheckBox.Checked)
            {
                proba = Proba.ONE_THOUSAND;
            }else if (fiftyHundreadCheckBox.Checked)
            {
                proba = Proba.FIFTEEN_HUNDRED;
            }
            List<Inscriere> inscrieriParticipantiCautati =  service.cautaParticipanti(varsta, proba);
            this.initializeListaParticipantiCautati(inscrieriParticipantiCautati);
            this.initTabelParticipantiCautati();
        }

        private void completareNrParticicaptiPerProba()
        {
            List<Inscriere> inscrieri = (List<Inscriere>) service.findAllInscrieri();
            int nrProbe50m = 0;
            int nrProbe100m = 0;
            int nrProbe1000m = 0;
            int nrProbe1500m = 0;
            foreach(Inscriere inscriere in inscrieri){
                if(inscriere.getProba().Equals(Proba.FIFTY))
                    nrProbe50m++;
                else if(inscriere.getProba().Equals(Proba.ONE_HUNDRED))
                    nrProbe100m++;
                else if(inscriere.getProba().Equals(Proba.ONE_THOUSAND))
                    nrProbe1000m++;
                else
                    nrProbe1500m++;
            }

            textBoxNrParticipanti50m.Text = nrProbe50m.ToString();
            textBoxNrParticipanti100m.Text = nrProbe100m.ToString();
            textBoxParticipanti1000m.Text = nrProbe1000m.ToString();
            textBoxParticipanti1500m.Text =  nrProbe1500m.ToString();
        }
        
    }
}